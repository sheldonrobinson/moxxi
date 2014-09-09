import QtQuick 2.2
import QtQuick.Controls 1.2

Item{
    id: root
    property alias button: button
    property alias badge: badge
    property alias text: text
    property alias fontsize: text.font.pixelSize
    property alias image: image
    property alias background: root.background
    property alias style: button.style
    property alias imageSource: image.source

    signal clicked

    Button {
        id: button
        width: root.width
        height: root.height
        anchors.verticalCenter: root.verticalCenter
        z:root.z

        Image
        {
            id: image
            height: root.height * 0.8
            width: root.height * 0.8
            anchors.verticalCenter: root.verticalCenter
            anchors.horizontalCenter: root.horizontalCenter
            //anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            visible: true
        }

        MouseArea {
            anchors.fill: root
            onClicked: {
               root.clicked()
            }
        }
    }

    Rectangle {
        id: badge

        anchors.top: root.top
        anchors.right: root.right
        radius: fontsize/2
        z:root.z+1

        Text {
            id: text
        }
    }

}
