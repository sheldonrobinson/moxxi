import QtQuick 2.2
import QtQuick.Window 2.1

Window {

    property int phone_width:768
    property int phone_height:1268

    id: appWindow
    visible: true
    width: phone_width
    height: phone_height

    MouseArea {
        anchors.fill: parent
    }
    Rectangle{
        id: screen
        visible: true
        width: parent.width
        height: parent.height

        Rectangle {
            property int title_height:40

            id: titleBar
            visible: true
            width: parent.width
            height: title_height

            anchors.top: screen.top

            Rectangle {
                id: sideBarToggleButton
                height:titleBar.height

                anchors.left: titleBar.left

            }
        }
    }
}
