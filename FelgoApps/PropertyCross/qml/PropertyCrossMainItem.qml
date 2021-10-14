import QtQuick 2.0
import Felgo 3.0
import "pages"
import "model"
Item {
    anchors.fill: parent

    Logic {
        id: logic

    }
    DataModel {
        id: dataModel
        dispatcher: logic
    }

    PropertyCrossMainPage {}
}
