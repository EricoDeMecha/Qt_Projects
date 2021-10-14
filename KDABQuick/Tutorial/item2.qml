import QtQuick 2.0

Item {
    width:300; height: 115
    TextInput {
        id: textElement
        x: 50; y: 50
        text: "Qt quick"
        font.family: "Helvitica"; font.pixelSize: 50
    }

    Rectangle {
        x: 50; y:  75; height: 5
        width: textElement.width
        color: "green"
    }
}
