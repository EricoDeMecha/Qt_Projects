import QtQuick 2.0


Image {
    x: 150; y : 150
    source: "imag.png"
    width: sourceSize.width + 2
    height: sourceSize.height + 2
    Component.onCompleted: console.log(sourceSize)
}
