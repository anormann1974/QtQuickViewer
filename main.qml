import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import QtQuickViewer 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 1280
    height: 720
    title: qsTr("QtQuickViewer - OpenSceneGraph Viewer based on QtQuick")

    function onShowConsole(value) {
        label.visible = labelFrame.visible = value
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")

            MenuItem {
                text: qsTr("File open...")
                iconSource: "open.png"
                onTriggered: fileDialog.open()
            }

            MenuSeparator {}

            MenuItem {
                text: qsTr("Exit")
                onTriggered: close()
            }
        }
    }

    toolBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            spacing: 6

            ToolButton {
                text: qsTr("Open")
                iconSource: "open.png"
                tooltip: qsTr("Open an OpenSceneGraph supported file")
                enabled: true
                onClicked: fileDialog.open()
            }

            Item { Layout.fillWidth: true }

            CheckBox {
                checked: label.visible
                text: qsTr("Show console output")
                Layout.alignment: Qt.AlignRight
                onClicked: onShowConsole(checked)
            }
        }
    }

    RenderView {
        id: renderView
        anchors.fill: parent
        focus: true
    }

    Rectangle {
        id: labelFrame
        radius: 5
        color: "white"
        border.color: "black"
        opacity: 0.8
        anchors.fill: label
        anchors.margins: -10
    }

    Text {
        id: label
        anchors.bottom: renderView.bottom
        anchors.left: renderView.left
        anchors.right: renderView.right
        anchors.margins: 20
        wrapMode: Text.WordWrap
        color: "black"
        horizontalAlignment: Text.AlignHCenter
        text: qsTr("You can manipulate the scene with your mouse")
    }

    FileDialog {
        id: fileDialog
        visible: false
        nameFilters: [ "Geometry files (*.osgb *.osgt *.osg *.ive *.flt *.obj *.3ds)", "All files (*)"]
        sidebarVisible: true
        selectMultiple: false
        selectFolder: false
        selectExisting: true
        title: qsTr("Open geometry file")

        onAccepted: {
            controller.loadFile(fileUrl)
        }
    }

    Controller {
        id: controller
        renderView: renderView
    }

    Timer {
        interval: 10
        running: true
        repeat: true
        onTriggered: renderView.update()
    }
}
