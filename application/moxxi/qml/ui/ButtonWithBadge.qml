import QtQuick 2.3
import QtQuick.Controls 1.2

Item{
    id: root
    default property alias button: myButton
    property alias badge: badge
    property alias text: badgeText.text
    property alias fontsize: badgeText.font.pixelSize
    property alias image: image
    property alias background: root.background
    property alias style: myButton.style
    property alias imageSource: image.source
    signal clicked

    visible: true

    Button {
        id: myButton
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
            id: badgeText
        }
    }
}
