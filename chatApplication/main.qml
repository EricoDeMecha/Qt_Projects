import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Server App")
    ColumnLayout {
        anchors.fill: parent
        ListView{
            Layout.fillHeight: true
            Layout.fillWidth:  true;
            model: ListModel{
                ListElement {
                    message:"Hi"
                }
            }
            delegate: ItemDelegate{
                text: message
            }
            ScrollBar.vertical: new ScrollBar()
        }
        RowLayout {
            TextField {
                id: textFieldMessage
                placeholderText: qsTr("Your  message...")
                Layout.fillWidth: true
                onAccepted:  buttonSend.clicked()
            }
            Button{
                id: buttonSend
                text: qsTr("Send")
                onClicked: {
                    console.log("Sent")
                    textFieldMessage.clear()
                }
            }
        }
    }
}
