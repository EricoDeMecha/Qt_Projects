import QtQuick 2.0

BorderImage {
    id: borderImage
    source: "file"
    width: 100; height: 100
    border {left: 5; right: 5; top: 5 ; bottom: 5}
    horizontalTileMode: BorderImage.Stretch
    verticalTileMode: BorderImage.Repeat
}
