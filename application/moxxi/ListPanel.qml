import QtQuick 2.2
import Moxxi 1.0

Row {
    id: listingsDelegate
    anchors.left: parent.left
    width: parent.width

    Image {
        id: image
        width: listingsDelegate.width / 3
        source: imageUrl
        fillMode: Image.PreserveAspectFit
    }

    Item {
        id: wrapper
        width: listingsDelegate.width * 2 / 3
        height: image.height
        Rectangle {

            color: ListView.isCurrentItem ? "darkgray" : "lightgray"
            border.color: "black"
            border.width: 4
            radius: ListView.isCurrentItem ? 2 : 0

            Column {

                Text {
                    id: listingname
                    text: name
                    font.bold: true
                    font.pixelSize: 12
                }
                Text {
                    id: listingDescription
                    text: description
                    font.pixelSize: 6
                }
            }
        }
    }
}
