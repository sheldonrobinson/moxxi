import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Enterprise.Controls 1.1
import QtQuick.Window 2.1




Window {

    property int phone_width:768
    property int phone_height:1268
    property Int camerabarheight: 15

    id: appWindow
    visible: true
    width: phone_width
    height: phone_height

    ExclusiveGroup {
         id: screenGroup

         Action {
             id: showStoreInput
             text: "Store"
             checkable: true
         }

         Action {
             id: showCartInput
             text: "Cart"
             checkable: true
         }

         Action {
             id: showListInput
             text: "List"
             checkable: true
         }
    }

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
                width: titleBar.height
                height:titleBar.height

                anchors.left: titleBar.left
                anchors.top: parent.top

                Image {
                    id: sBTB_img
                    x: parent.left
                    y: parent.top

                    anchors.fill: parent

                    visible: true
                    source: "res/images/list.svg"
                }
            }

            Row {
                id: screenChkBoxGrp
                anchors.verticalCenter: parent.verticalCenter

                anchors.right: parent.right

                visible: true

                RadioButton {
                    text: qsTr("Store")
                    exclusiveGroup: screenGroup
                    checked: true

                }
                RadioButton {
                    text: qsTr("Cart")
                    exclusiveGroup: screenGroup
                }

                RadioButton {
                    text: qsTr("List")
                    exclusiveGroup: screenGroup
                }

            }

            Rectangle {
                id: titleSlot
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter


                visible: true

                Text {
                    id: screenTitle
                    text: qsTr("Shop")
                }
            }

        }

        Rectangle {
            id: bCamera
            anchors.bottom: parent.bottom

            width: parent.width
            height: camerabarheight

            visible: true

        }

        Rectangle {
            id: contentPanel

            anchors.top: titleBar.bottom
            anchors.left: parent.left

            width: parent.width
            height: parent.height - titleBar.height - bCamera.height

            visible: true
        }



    }
}
