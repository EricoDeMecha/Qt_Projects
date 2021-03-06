import QtQuick 2.0
import Felgo 3.0

Item {
    property alias dispatcher: logicConnection.target
    Client {
        id: client
    }

    Connections {
        id: logicConnection
        onSearchListings: {
            client.search(searchText, _.responseCallback)
        }
    }

    Item {
        id: _

        function responseCallback(obj){
            var response = obj.response
            var code = response.application_response_code
            console.debug("Server returned app code: ", code)
        }
    }
}
