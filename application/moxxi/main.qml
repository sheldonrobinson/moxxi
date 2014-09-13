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

    property ListModel galleryModel: ListModel {
                                     }
    property ListModel queriesModel:  ListModel {
                                     }

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

        function hide() {
            bgLoader.sourceComponent = null
            coverFlowLoader.sourceComponent = null
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

            Button {
                id: sideBarToggleButton

                x: -8

                anchors.verticalCenter: parent.verticalCenter

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

                style: ButtonStyle {
                    label: Text {
                        text: control.text
                        font.pixelSize: titlebar.title_fontsize
                        font.family: "DejaVu Sans"
                        anchors.margins: 0
                        horizontalAlignment: Text.left
                    }
                    background: Rectangle {
                        implicitHeight: parent.height * 0.6
                        implicitWidth: parent.height * 0.6
                        border.width: 2
                        border.color: screenChkBoxGrp.border_color
                        color: "transparent"
                        visible: true
                        radius: screenChkBoxGrp.button_radius
                    }
                }


                onClicked: {
                    queryPanelLoader.toggle()
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

                    id: iconBox

                    property double iconScaling: 0.6
                    property double iconBoundingBox: 0.8

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

                        Image {
                            id: shopicon
                            height: parent.height * iconBox.iconScaling
                            width: shopicon.height
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
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
                                implicitHeight: titlebar.height * iconBox.iconBoundingBox
                                implicitWidth: titlebar.height * iconBox.iconBoundingBox
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
                            when: (screen.state != "SHOP")
                            PropertyChanges {
                                target: rbShop
                                iconSource: "qrc:res/images/store-disabled.svg"
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
                        iconSource: "qrc:res/images/Shopping-Cart-enabled.svg"

                        Image {
                            id: charticon
                            height: parent.height * iconBox.iconScaling
                            width: charticon.height
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
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
                                implicitHeight: titlebar.height * iconBox.iconBoundingBox
                                implicitWidth: titlebar.height * iconBox.iconBoundingBox
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
                                iconSource: "qrc:res/images/Shopping-Cart-full-disabled.svg"
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

                        iconSource: "qrc:res/images/note-2-enabled.svg"

                        Image {
                            id: listicon
                            height: parent.height * iconBox.iconScaling
                            width: listicon.height
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
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
                                implicitHeight: titlebar.height * iconBox.iconBoundingBox
                                implicitWidth: titlebar.height * iconBox.iconBoundingBox
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
                            when: (screen.state != "LIST")
                            PropertyChanges {
                                target: rbList
                                iconSource: "qrc:res/images/note-2-full-disabled.svg"
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
                    }
                }
            }
        }

        Rectangle {
            id: bCamera
            anchors.bottom: parent.bottom

            width: parent.width
            height: camerabarheight
            z: titlebar.z
            visible: true
        }

        Rectangle {
            id: contentPanel
            anchors.top: titlebar.bottom
            anchors.left: screen.left
            anchors.right: screen.right
            anchors.bottom: bCamera.top
            z: parent.z + 1
            visible: true

            Component {
                id: listingsDelegate

                Row {
                    id: contentRow
                    property int rowSpacing: 5
                    property string rowOddColor: "#cccccc"
                    property string rowEvenColor: "#eeeeee"
                    property int swipeOffPosition: 0
                    property string swipeBuyColorStart: ""
                    width: screen.width
                    z: 1

                    Rectangle {
                        width: screen.width
                        height: renderedRow.height + contentRow.rowSpacing
                        color: model.index % 2 == 0 ? rowEvenColor : rowOddColor
                        border.color: "black"
                        border.width: rowSpacing
                        anchors.verticalCenter: parent.verticalCenter
                        z: 1

                        Row {
                            id: renderedRow
                            width: screen.width - contentRow.rowSpacing * 2
                            height: Math.max(theImage.implicitHeight,
                                             theTextArea.implicitHeight)
                            spacing: rowSpacing

                            z: 1

                            Image {
                                id: theImage
                                width: screen.width / 8 - contentRow.rowSpacing * 2
                                anchors.verticalCenter: parent.verticalCenter
                                fillMode: Image.PreserveAspectFit
                                source: model.listingImageUrl
                                visible: true

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        contentRow.showCoverflow()
                                    }
                                }
                            }

                            Column {
                                id: theTextArea
                                x: screen.width / 8 + contentRow.rowSpacing
                                width: parent.width * 3 / 4 - contentRow.rowSpacing * 2

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
                                    font.bold: true
                                    font.pointSize: 12
                                    text: model.listingPrice
                                }
                            }
                        }
                    }
                    function showCoverflow() {
                        galleryModel.clear()
                        var numOfUrl = model.listingImageUrlsStrings.length
                        if (numOfUrl > 0) {
                            for (var i = 0; i < numOfUrl; i++) {
                                galleryModel.append({
                                                        imageUrl: model.listingImageUrlsStrings[i]
                                                    })
                            }
                        } else {
                            galleryModel.append({
                                                    imageUrl: model.listingImageUrlString
                                                })
                        }
                        bgLoader.sourceComponent = coverflowBackground
                        coverFlowLoader.sourceComponent = coverFlow
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

        Loader {
            id: queryPanelLoader
            anchors.top: titlebar.bottom
            height: contentPanel.height
            width: screen.width * 0.75
            z: titlebar.z
            visible: true

            Component {
                id: queryPanel

                Rectangle {
                    id: queryPanelBoundingBox

                    anchors.fill: parent
                    color: "black"
                    opacity: 0.5

                    Column {
                        anchors.fill: parent
                        spacing: 20
                        Rectangle {
                            id: queryTextBox
                            anchors.topMargin: 70
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: queryPanelBoundingBox.width * 0.9
                            color: "black"
                            height: queryText.height + 30
                            border.color: "white"
                            border.width: 10
                            radius: 5
                            z: queryPanelLoader.z + 1
                            TextInput {
                                id: queryText

                                z: queryPanelLoader.z + 1
                                activeFocusOnPress: true
                                anchors.left: parent.left
                                anchors.leftMargin: parent.border.width + 10
                                anchors.verticalCenter: parent.verticalCenter
                                height: 36

                                text: theModel.fts
                                font.pointSize: 24
                                font.bold: true
                                readOnly: false
                                renderType: Text.NativeRendering
                                color: "white"
                                cursorVisible: true
                                width: parent.width - 2 * parent.border.width - 20

                                onAccepted: {

                                    theModel.fts = queryText.text;

                                    if (theModel.fts.length > 0) {
                                        queryHistory.append(theModel.fts);
                                    }

                                    queryPanelLoader.toggle();
                                }
                            }

                            MouseArea {
                                anchors.fill: queryTextBox
                                onClicked: {
                                    queryText.forceActiveFocus()
                                }
                            }
                        }

                            Repeater {
                                id: queryHistory
                                property int historyLength: 10
                                model: queriesModel
                                delegate: Rectangle {
                                    id: historyItem
                                    color: "black"
                                    border.color: "darkgray"
                                    border.width: 2
                                    radius: 5
                                    width: queryTextBox.width
                                    height: historicalquery.height + 10
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    visible: true
                                    z: queryPanelLoader.z + 1
                                    Text {
                                        id: historicalquery
                                        text: model.query
                                        anchors.left: parent.left
                                        anchors.leftMargin: parent.border.width + 10
                                        anchors.verticalCenter: parent.verticalCenter
                                        height: 14
                                        color: "white"
                                        font.pixelSize: 12
                                    }

                                    MouseArea {
                                        anchors.fill: parent

                                        onClicked: {
                                            theModel.fts = model.query;
                                            queryPanelLoader.toggle();
                                        }
                                    }
                                }

                                function append(newquery) {
                                    if (queriesModel.count > queryHistory.historyLength - 1) {
                                           queriesModel.remove(queriesModel.count-1);
                                    }

                                    queriesModel.insert(0,{
                                                            query: newquery
                                                        });
                                }
                            }

                            Component.onCompleted: {
                                queryText.forceActiveFocus()
                            }


                        }

                }
            }


            function toggle() {
                if (queryPanelLoader.sourceComponent) {
                    queryPanelLoader.sourceComponent = null
                } else {
                    queryPanelLoader.sourceComponent = queryPanel
                }
            }
        }

        Loader {

            id: bgLoader
            anchors.fill: parent
            z: contentPanel.z + 3

            Component {
                id: coverflowBackground

                Rectangle {

                    anchors.fill: parent
                    color: "black"
                    visible: true
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
        }
    }
}
