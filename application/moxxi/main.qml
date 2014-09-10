import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.1
import Moxxi 1.0


Window {

    property int phone_width: 810
    property int phone_height: 1440
    property int camerabarheight: 40
    property int buttonspacing: 5
    property int title_height: 64


    //property string list_icon_url
    //property string cart_icon_url
    //property string shop_icon_url
    //property string slider_icon_url
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

    Rectangle {
        id: screen
        visible: true
        width: parent.width
        height: parent.height

        state: "SHOP"

        states: [
            State {
                name: "SHOP"
                PropertyChanges {
                    target: screenTitle
                    text: qsTr("BOUTIQUE")
                }
            },
            State {
                name: "CART"
                PropertyChanges {
                    target: screenTitle
                    text: qsTr("CART")
                }
            },
            State {
                name: "LIST"
                PropertyChanges {
                    target: screenTitle
                    text: qsTr("WISHLIST")
                }
            }
        ]

        Rectangle {

            property int title_fontsize: 28
            x: 0
            id: titlebar
            visible: true
            width: parent.width
            height: title_height
            anchors.topMargin: 0

            anchors.top: screen.top

            gradient: Gradient {
                GradientStop {
                    position: 0.0
                    color: "lightgray"
                }
                GradientStop {
                    position: 0.95
                    color: "lightgray"
                }
                GradientStop {
                    position: 1.0
                    color: "darkgray"
                }
            }

            Rectangle {
                id: sideBarToggleButton
                height: parent.height * 0.6
                width: parent.height * 0.6
                x: -8

                anchors.verticalCenter: parent.verticalCenter
                //anchors.left: parent.left
                color: "transparent"

                //anchors.top: parent.top
                Image {
                    id: slidericon
                    height: parent.height * 0.5
                    width: parent.height * 0.5
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    //anchors.fill: parent
                    fillMode: Image.PreserveAspectFit
                    visible: true
                    source: "res/images/apps.svg"
                }
            }

            GroupBox {
                id: screenChkBoxGrp

                property int button_radius: 8
                property string border_color: "#333333"
                property string bgcolor: "#777777"
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                height: parent.height

                Row {

                    height: parent.height
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    spacing: buttonspacing

                    visible: true

                    Button {
                        id: rbShop
                        exclusiveGroup: screenGroup
                        activeFocusOnPress: true
                        checked: true
                        checkable: true
                        anchors.verticalCenter: parent.verticalCenter
                        iconSource: "res/images/store-enabled.svg"


                        //anchors.horizontalCenter: parent.horizontalCenter
                        Image {
                            id: shopicon
                            height: parent.height * 0.8
                            width: parent.height * 0.8
                            anchors.verticalCenter: parent.verticalCenter
                            //anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            source: rbShop.iconSource
                            visible: true
                        }

                        style: ButtonStyle {
                            label: Text {
                                text: control.text
                                font.pixelSize: titlebar.title_fontsize
                                font.family: "DejaVu Sans"
                                anchors.margins: 0
                                horizontalAlignment: Text.left
                            }
                            background: Rectangle {
                                implicitHeight: titlebar.height * 0.95
                                implicitWidth: titlebar.height * 0.95
                                border.width: control.checked
                                              || control.activeFocus ? 2 : 0
                                border.color: control.checked
                                              || control.activeFocus ? screenChkBoxGrp.border_color : "transparent"
                                color: control.checked
                                       || control.activeFocus ? screenChkBoxGrp.bgcolor : "transparent"
                                visible: control.checked || control.activeFocus
                                radius: screenChkBoxGrp.button_radius
                                //gradient: Gradient {
                                //    GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                                //    GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                                //}
                            }
                        }
                        states: State {
                            name: "INACTIVE"
                            when: (screen.state != "SHOP")
                            PropertyChanges {
                                target: rbShop
                                iconSource: "res/images/store-disabled.svg"
                            }
                            PropertyChanges {
                                target: rbShop
                                checked: false
                            }
                        }
                        onClicked: {
                            screen.state = "SHOP"
                            rbShop.forceActiveFocus()
                            rbShop.checked = true
                        }
                    }

                    Button {
                        id: rbCart
                        exclusiveGroup: screenGroup
                        activeFocusOnPress: true
                        checked: true
                        checkable: true
                        anchors.verticalCenter: parent.verticalCenter
                        iconSource: "res/images/Shopping-Cart-enabled.svg"


                        //anchors.horizontalCenter: parent.horizontalCenter
                        Image {
                            id: charticon
                            height: parent.height * 0.8
                            width: parent.height * 0.8
                            anchors.verticalCenter: parent.verticalCenter
                            //anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            source: rbCart.iconSource
                            visible: true
                        }

                        style: ButtonStyle {
                            label: Text {
                                text: control.text
                                font.pixelSize: titlebar.title_fontsize
                                font.family: "DejaVu Sans"
                                anchors.margins: 0
                                horizontalAlignment: Text.left
                            }
                            background: Rectangle {
                                implicitHeight: titlebar.height * 0.95
                                implicitWidth: titlebar.height * 0.95
                                border.width: control.checked
                                              || control.activeFocus ? 2 : 0
                                border.color: control.checked
                                              || control.activeFocus ? screenChkBoxGrp.border_color : "transparent"
                                color: control.checked
                                       || control.activeFocus ? screenChkBoxGrp.bgcolor : "transparent"
                                visible: control.checked || control.activeFocus
                                radius: screenChkBoxGrp.button_radius
                                //gradient: Gradient {
                                //    GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                                //    GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                                //}
                            }
                        }

                        states: State {
                            name: "INACTIVE"
                            when: (screen.state != "CART")
                            PropertyChanges {
                                target: rbCart
                                iconSource: "res/images/Shopping-Cart-full-disabled.svg"
                            }
                            PropertyChanges {
                                target: rbCart
                                checked: false
                            }
                        }
                        onClicked: {
                            screen.state = "CART"
                            rbCart.forceActiveFocus()
                            rbCart.checked = true
                        }
                    }
                    Button {
                        id: rbList
                        exclusiveGroup: screenGroup
                        activeFocusOnPress: true
                        checked: true
                        checkable: true
                        anchors.verticalCenter: parent.verticalCenter
                        iconSource: "res/images/note-2-enabled.svg"


                        //anchors.horizontalCenter: parent.horizontalCenter
                        Image {
                            id: listicon
                            height: parent.height * 0.8
                            width: parent.height * 0.8
                            anchors.verticalCenter: parent.verticalCenter
                            //anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            source: rbList.iconSource
                            visible: true
                        }

                        style: ButtonStyle {
                            label: Text {
                                text: control.text
                                font.pixelSize: titlebar.title_fontsize
                                font.family: "DejaVu Sans"
                                anchors.margins: 0
                                horizontalAlignment: Text.left
                            }
                            background: Rectangle {
                                implicitHeight: titlebar.height * 0.95
                                implicitWidth: titlebar.height * 0.95
                                border.width: control.checked
                                              || control.activeFocus ? 2 : 0
                                border.color: control.checked
                                              || control.activeFocus ? screenChkBoxGrp.border_color : "transparent"
                                color: control.checked
                                       || control.activeFocus ? screenChkBoxGrp.bgcolor : "transparent"
                                visible: control.checked || control.activeFocus
                                radius: screenChkBoxGrp.button_radius
                                //gradient: Gradient {
                                //    GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                                //    GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                                //}
                            }
                        }

                        states: State {
                            name: "INACTIVE"
                            when: (screen.state != "LIST")
                            PropertyChanges {
                                target: rbList
                                iconSource: "res/images/note-2-full-disabled.svg"
                            }
                            PropertyChanges {
                                target: rbList
                                checked: false
                            }
                        }
                        onClicked: {
                            screen.state = "LIST"
                            rbList.forceActiveFocus()
                            rbList.checked = true
                        }
                    }
                }
            }

            Rectangle {
                id: titleSlot
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: sideBarToggleButton.right
                anchors.right: screenChkBoxGrp.left
                anchors.leftMargin: 2

                visible: true

                Rectangle {
                    height: parent.height * 0.9
                    color: "#aaaaaa"
                    width: parent.width * 0.9
                    anchors.verticalCenter: parent.verticalCenter
                    radius: screenChkBoxGrp.button_radius * 3
                    border.color: "#000000"
                    border.width: 8

                    Text {
                        id: screenTitle
                        text: qsTr("BOUTIQUE")
                        horizontalAlignment: Text.AlignLeft
                        font.family: "Courier"
                        font.capitalization: Font.SmallCaps
                        font.pointSize: titlebar.title_fontsize
                        verticalAlignment: Text.AlignVCenter
                        anchors.verticalCenter: parent.verticalCenter
                        //anchors.bottom: parent.bottom
                    }
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

        Rectangle{

            id: contentPanel
            //y: appWindow.title_height
            anchors.top: titlebar.bottom
            anchors.left: screen.left
            anchors.right: screen.right
            anchors.bottom: bCamera.top

            //width: parent.width
            //height: parent.height - titlebar.height - bCamera.height

            visible: true

            Component{
                   id: listingsDelegate
                       Row {
                           width:screen.width

                           Image {
                               //id: listingImg
                               width: parent.width/16
                               //height: 250
                               source: model.listingImageUrl
                               fillMode: Image.PreserveAspectFit
                           }
                           Column{
                           //Text { text: '<b>ImageUtrl:</b> ' + model.listingImageUrl }
                           Text {
                               text: model.listingTweet
                               wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                               //anchors.verticalCenter: listingsView.currentItem.verticalCenter
                               width: 540
                           }
                           //Text { text: '<b>Description:</b> ' + model.listingDescription }
                           }
                       }

//                       Image {
//                           //id: listingImg
//                          // width: listingsDelegate.width / 3
//                           height: parent.height
//                           source: listingImageUrl
//                           fillMode: Image.PreserveAspectFit
//                           visible: true
//                       }

//                       Text {
//                           //id: lstname
//                           //font.bold: true
//                           font.pixelSize: 12
//                           text: listingName
//                           visible: true
//                       }
//                       Text {
//                           //id: listingDescription
//                           font.pixelSize: 6
//                           text: listingDescription
//                           visible: true

//                       }
                }

            ListView {
               id: listingsView
               model:  theModel
               //y: appWindow.title_height
               orientation: ListView.Vertical
               snapMode: ListView.SnapToItem
               delegate: listingsDelegate
               anchors.fill: contentPanel
               //anchors.top: titlebar.bottom
               //anchors.bottom: bCamera.top

              }

           }




//            Rectangle {
//                id: listingsDelegate
//                anchors.left: parent.left
//                width: parent.width
//                height: 100

//                Image {
//                    id: listingImg
//                    width: listingsDelegate.width / 3
//                    height: parent.height
//                    source: listingImageUrl
//                    fillMode: Image.PreserveAspectFit
//                }

//                Rectangle {
//                    //id: wrapper
//                    width: listingsDelegate.width * 2 / 3
//                    height: listingImg.height
//                        color: ListView.isCurrentItem ? "darkgray" : model.index % 2 == 0 ? "lightgray" : "gray"
//                        border.color: "black"
//                        border.width: 4
//                        //radius: ListView.isCurrentItem ? 2 : 0

//                     Column {

//                        Text {
//                            id: lstname
//                            font.bold: true
//                            font.pixelSize: 12
//                            text: listingName
//                        }
//                        Text {
//                            //id: listingDescription
//                            font.pixelSize: 6
//                            text: listingDescription
//                        }
//                    }
//                }
//            }

    }

    Component.onCompleted: {
        console.log("listingsView.model:"+theModel.count)
        console.log("listingsView.model:"+listingsView.model)
        console.log("theModel.query:"+theModel.query)
    }
}
