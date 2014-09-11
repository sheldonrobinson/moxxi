import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.1
import Moxxi 1.0

import "qml/ui"

Window {

    property int phone_width: 810
    property int phone_height: 1440
    property int camerabarheight: 40
    property int buttonspacing: 5
    property int title_height: 64

    property ListModel galleryModel: ListModel {}

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

        Rectangle {
            id: coverflowBackground

            anchors.fill: parent
            color: "black"
            z: parent.z
            visible:true

            function hide(){
                //coverFlow.destroy();
                coverflowBackground.z = parent.z;
                coverFlowLoader.sourceComponent = null;
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("coverflowBackground.clicked")
                    hide();
                }
            }
        }

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
            z: contentPanel.z + 2
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
                color: "transparent"

                Image {
                    id: slidericon
                    height: parent.height * 0.5
                    width: parent.height * 0.5
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
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

                        Image {
                            id: charticon
                            height: parent.height * 0.8
                            width: parent.height * 0.8
                            anchors.verticalCenter: parent.verticalCenter
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
            z: contentPanel.z + 2
            visible: true
        }

        Rectangle {

            id: contentPanel
            //y: appWindow.title_height
            anchors.top: titlebar.bottom
            anchors.left: screen.left
            anchors.right: screen.right
            anchors.bottom: bCamera.top
            z: parent.z + 1


            //width: parent.width
            //height: parent.height - titlebar.height - bCamera.height
            visible: true

            Component {
                id: listingsDelegate

                Row {
                    property int rowSpacing: 5
                    property string rowOddColor: "#cccccc"
                    property string rowEvenColor: "#eeeeee"
                    property int swipeOffPosition: 0
                    property string swipeBuyColorStart: ""
                    width: screen.width
                    height: childrenRect.height
                    z: 1

                    Rectangle {
                        width: screen.width
                        height: childrenRect.height + rowSpacing
                        color: model.index % 2 == 0 ? rowEvenColor : rowOddColor
                        border.color: "black"
                        border.width: rowSpacing
                        anchors.verticalCenter: parent.verticalCenter
                        z: 1

                        Row {
                            width: screen.width - rowSpacing*2
                            height: childrenRect.height
                            spacing: rowSpacing
                            z: 1

                            Image {
                                y: rowSpacing
                                width: screen.width / 8 - rowSpacing*2
                                anchors.verticalCenter: parent.verticalCenter
                                fillMode: Image.PreserveAspectFit
                                source: model.listingImageUrl
                                visible: true

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        galleryModel.clear();
                                        var numOfUrl = model.listingImageUrlsStrings.length;
                                        //var imageUrl = "";
                                        console.log("model.listingImageUrlsStrings: "+model.listingImageUrlsStrings);
                                        console.log("model.listingImageUrlString: "+model.listingImageUrlString);
                                        if(numOfUrl > 0){
                                            for (var i = 0; i < numOfUrl; i++) {
                                                     console.log(i+":"+model.listingImageUrlsStrings[i]);
                                                     //imageUrl = model.listingImageUrlsStrings[i];
                                                     galleryModel.append({"imageUrl":model.listingImageUrlsStrings[i]});
                                            }
                                        }else{
                                            console.log("image:"+model.listingImageUrlString);
                                            //imageUrl = model.listingImageUrlString;
                                            galleryModel.append({"imageUrl":model.listingImageUrlString});
                                        }

                                        console.log("galleryModel: "+ galleryModel);
                                        coverflowBackground.z = contentPanel.z + 3;
                                        coverFlowLoader.sourceComponent = coverFlow;

                                    }
                                }
                            }

                            Column {
                                x: screen.width / 8 + rowSpacing
                                width: parent.width * 3 / 4 - rowSpacing*2

                                Text {
                                    text: model.listingName
                                    font.bold: true
                                    style: Text.Raised
                                    font.pointSize: 16

                                    MouseArea {
                                        anchors.fill: parent

                                        onClicked: {
                                            Qt.openUrlExternally(
                                                        model.listingUrl)
                                        }
                                    }
                                }
                                Text {

                                    text: model.listingTweet
                                    width: parent.width
                                    wrapMode: Text.Wrap
                                    font.pointSize: 9
                                }
                                Text {
                                    text: '<b>Price</b> ' + model.listingPrice
                                }

                            }
                        }

                        Keys.onRightPressed: {
                            console.log("Swipe Right;")
                        }

                        Keys.onLeftPressed: {
                            console.log("Swipe Left;")
                        }

                        SwipeArea {
                            anchors.fill: parent
                            onSwipe: {
                                switch (direction) {
                                case "left":
                                    {
                                        console.log("Left Swipe");
//                                        var component = Qt.createComponent("qml/ui/RowGradient.qml");
//                                        if (component.status == Component.Ready){
//                                            var comColorLeft = model.index % 2 == 0 ? rowEvenColor : rowOddColor;
//                                            var comColorMid = model.index % 2 == 0 ? rowEvenColor : rowOddColor;
//                                            var comColorRight = "green";
//                                            rowGradient.createObject(parent,{"colorLeft" : compColorLeft,"colorRight" : compColorRight,"colorMid" : compColorMid, "breakpoint":1});

//                                         }
                                    }
                                    break
                                case "right":
                                    {
                                        console.log("Right Swipe");
//                                        var component = Qt.createComponent("qml/ui/RowGradient.qml");
//                                        if (component.status == Component.Ready){
//                                            var comColorLeft = model.index % 2 == 0 ? rowEvenColor : rowOddColor;
//                                            var comColorMid = model.index % 2 == 0 ? rowEvenColor : rowOddColor;
//                                            var comColorRight = "blue";
//                                            rowGradient.createObject(parent,{"colorLeft" : compColorLeft,"colorRight" : compColorRight,"colorMid" : compColorMid, "breakpoint":1});

//                                         }
                                    }
                                    break
                                }
                            }
                            onCanceled: {

                            }
                        }
                    }


                }

            }

            ListView {
                id: listingsView
                model: theModel
                contentX: 0
                contentY: appWindow.title_height
                orientation: ListView.Vertical
                snapMode: ListView.SnapToItem
                delegate: listingsDelegate
                anchors.fill: contentPanel
            }

        }
    }

    Loader {
        id: coverFlowLoader
        anchors.fill: parent
        z: contentPanel.z + 4

        Component {
            id: coverFlow

            CoverFlow {
                anchors.fill: parent
            }

        }

        Component.onCompleted: {
            imageView.closed.connect(coverflowBackground.hide())
        }
    }

//    Loader {
//        id: busyIndicatorLoader

//        width: 150
//        height: 150
//        anchors.centerIn: parent

//        sourceComponent: busyIndicator
//        Component {
//            id: busyIndicator

//            BusyIndicator {
//                running: true
//            }
//        }
//    }

    //ListModel{
    //    id: galleryModel
    //}


}
