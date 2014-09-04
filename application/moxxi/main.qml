import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.1




Window {

    property int phone_width:1080
    property int phone_height:1920
    property int camerabarheight: 40

    id: appWindow
    visible: true
    width: phone_width
    height: phone_height

    Image {
        id: store_svg
        source: "res/images/store.svg"
        visible: false
    }

    Image {
        id: cart_enabled_svg
        source: "res/images/Shopping-Cart-enabled.svg"
        visible: false
    }

    Image {
        id: cart_empty_disabled_svg
        source: "res/images/Shopping-Cart-empty-disabled.svg"
        visible: false
    }

    Image {
        id: cart_full_disabled_svg
        source: "res/images/Shopping-Cart-full-disabled.svg"
        visible: false
    }

    Image {
        id: notes_empty_disabled_svg
        source: "res/images/note-2-empty-disabled.svg"
        visible: false
    }

    Image {
        id: notes_full_disabled_svg
        source: "res/images/note-2-full-disabled.svg"
        visible: false
    }

    Image {
        id: notes_enabled_svg
        x: 0
        y: 0
        width: 512
        height: 512
        source: "res/images/note-2-enabled.svg"
        visible: false
    }

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
                    source: "res/images/apps.svg"
                }
            }

            Row {
                id: screenChkBoxGrp
                anchors.verticalCenter: parent.verticalCenter

                anchors.right: parent.right

                height: parent.height

                visible: true

                RadioButton {
                    id: rbShop
                    //text: qsTr("Store")
                    exclusiveGroup: screenGroup
                    checked: true


                    style: RadioButtonStyle
                    {
                            label: Text
                            {
                                text: control.text
                                font.pixelSize: 9
                                font.family: "DejaVu Sans"
                                anchors.margins: 0
                                horizontalAlignment: Text.left
                            }
                            indicator: Rectangle
                            {
                            implicitWidth: parent.height
                            implicitHeight: parent.height
                            radius: 1
                            border.color: control.activeFocus ? "darkblue" : "gray"
                            border.width: 1



                            Image
                            {
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.fill: parent
                                fillMode: Image.PreserveAspectFit
                                source: "res/images/store.svg"
                                visible: true
                            }
                        }
                    }
                    onClicked:
                    {
                        //TBD
                    }
                }


            RadioButton {
                id: rbCart
                //text: qsTr("Cart")
                exclusiveGroup: screenGroup



                style: RadioButtonStyle
                {
                    label: Text
                    {
                    text: control.text
                    font.pixelSize: 9
                    font.family: "DejaVu Sans"
                    anchors.margins: 0
                    horizontalAlignment: Text.left
                    }
                    indicator: Rectangle
                    {
                    implicitWidth: parent.height
                    implicitHeight: parent.height
                    radius: 1
                    border.color: control.activeFocus ? "darkblue" : "gray"
                    border.width: 1


                        Image
                        {
                            id: activeChartImg
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            source: control.checked ? "res/images/Shopping-Cart-enabled.svg" : "res/images/Shopping-Cart-full-disabled.svg"
                             visible: true
                        }

                    }
                }
                onClicked:
                {
                    //TBD
                }


           }

                RadioButton {
                    id: rbList
                    //text: qsTr("List")
                    exclusiveGroup: screenGroup

                    style: RadioButtonStyle
                    {
                        label: Text
                        {
                            text: control.text
                            font.pixelSize: 9
                            font.family: "DejaVu Sans"
                            anchors.margins: 0
                            horizontalAlignment: Text.left
                        }
                        indicator: Rectangle
                        {
                            implicitWidth: parent.height
                            implicitHeight: parent.height
                            radius: 1
                            border.color: control.activeFocus ? "darkblue" : "gray"
                            border.width: 1



                            Image
                            {
                                id: activeListImg
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.fill: parent
                                fillMode: Image.PreserveAspectFit
                                source: control.checked ? "res/images/note-2-enabled.svg" : "res/images/note-2-full-disabled.svg"
                                visible: true
                                //visible: control.checked
                            }
                        }
                    }
                    onClicked:
                    {
                        //TBD
                    }
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
