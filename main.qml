import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 1280
    height: 720
    title: qsTr("QtQuickOSG - OpenSceneGraph Viewer bases on QtQuick 2")

    function onShowConsole(value) {
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")

            MenuItem {
                text: qsTr("File open...")
                iconSource: "open.png"
                onTriggered: fileDialog.open()
            }
        }
    }

    toolBar: ToolBar {
        RowLayout {
            //anchors.left: parent.left
            //anchors.top: parent.top
            //anchors.bottom: parent.bottom
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
                checked: false
                text: qsTr("Show console output")
                Layout.alignment: Qt.AlignRight
                onClicked: onShowConsole(checked)
            }
        }
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

        onRejected: {
            console.log("File rejected")
        }
    }

}
