import QtQuick 2.0
import Felgo 3.0

Page {

    id: _searchPage
    title: qsTr("Property Cross")
    rightBarItem: NavigationBarRow{
        ActivityIndicatorBarItem{
            visible: true
        }
        IconButtonBarItem{
            icon: IconType.heart
            title: qsTr("Favourites")
            onClicked:  showListings(true)
        }
    }
    Column {
        id: contentCol
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: contentPadding
        spacing: contentPadding

        AppText {
            width: parent.width
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.pixelSize: sp(12)
            text:qsTr("Use the form below to search for houses to buy. You can search by place, or click 'My location'.")
        }

        AppText {
            width: parent.width
            font.pixelSize:  sp(12)
            color: Theme.secondaryTextColor
            text: qsTr("Hint: You can quickly find something by typing 'London'")
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        }

        AppTextField{
            id: searchInput
            width: parent.width
            showClearButton: true
            placeholderText: qsTr("Search...")
            inputMethodHints: Qt.ImhNoPredictiveText

            onTextChanged: showRecentSearches()
            onEditingFinished: if(navigationStack.currentPage === SearchPage){
                                   search();
                               }
        }

        Row {
            spacing: contentPadding
            AppButton {
                text: qsTr("Go")
                onClicked: search()
            }
            AppButton {
                id: _getLocationBtn
                text: qsTr("Get my location")
                enabled: true
                onClicked: {
                    searchInput.text = ""
                    searchInput.placeholderText = qsTr("Looking for my location")
                    _getLocationBtn.enabled = false
                }
            }
        }
    }

    function showRecentSearches(){
        console.debug(searchInput.text);
    }
    function search(){
        logic.searchListings(searchInput.text, true)
    }
    function showListings(favourites){

    }
}
