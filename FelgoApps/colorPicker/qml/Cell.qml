import QtQuick 2.0
import Felgo 3.0

Item {
      id: container
      property alias cellColor: rectangle.color
      signal clicked(cellColor: color)
      width: 100; height: 100

      Rectangle {
          id: rectangle
          border.color: "white"
          anchors.fill: parent
      }

      MouseArea{
          anchors.fill: parent
          onClicked: container.clicked(container.cellColor)
      }
}
