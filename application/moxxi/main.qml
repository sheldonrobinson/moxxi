import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.1
import Moxxi 1.0

import "qml/ui"

Window {

    //property int phone_width: 810
    //property int phone_height: 1440
    property int camerabarheight: 20
    property int buttonspacing: 5
    property int title_height: 64

    property ListModel galleryModel: ListModel {
                                     }
    property ListModel queriesModel:  ListModel {
                                     }

    id: appWindow

    height: screenheight
    width: screenwidth

    visible: true
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
        anchors.fill: parent

        function hideCoverFlow() {
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
                height: title_height * 0.5
                width: title_height * 0.5
                x: -8

                anchors.verticalCenter: parent.verticalCenter
                z: titlebar.z
                //iconSource: "qrc:res/images/justify.svg"

                Image {
                    id: slidericon
                    anchors.fill: parent
                    //anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:res/images/justify.svg"  //sideBarToggleButton.iconSource
                    visible: true

                }

                style: ButtonStyle {

                    background: Rectangle {
                        implicitHeight:sideBarToggleButton.height
                        implicitWidth: sideBarToggleButton.width
                        border.width: 5
                        border.color: "darkgray"
                        color: "transparent"
                        visible: true
                        radius: 5
                    }
                }


                onClicked: {
                    queryPanelLoader.toggle()
                }
            }

            Rectangle {
                id: titleSlot
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: sideBarToggleButton.right
                anchors.right: screenChkBoxGrp.left
                //anchors.leftMargin: 10
                z: titlebar.z
                visible: true

                    Text {
                        id: screenTitle
                        text: qsTr("BOUTIQUE")
                        //horizontalAlignment: Text.AlignLeft
                        renderType: Text.NativeRendering
                        font.capitalization: Font.SmallCaps
                        font.pointSize: titlebar.title_fontsize
                        verticalAlignment: Text.AlignVCenter
                        anchors.verticalCenter: parent.verticalCenter
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
                z: titlebar.z
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
                        id: rbSearch
                        exclusiveGroup: screenGroup
                        activeFocusOnPress: true
                        checked: true
                        checkable: true
                        anchors.verticalCenter: parent.verticalCenter

                        //iconSource: "qrc:res/images/magnifier-2.svg"

                        Image {
                            id: search
                            height: parent.height * iconBox.iconScaling
                            width: rbSearch.height
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            fillMode: Image.PreserveAspectFit
                            source: "qrc:res/images//magnifier-2.svg" //rbSearch.iconSource
                            visible: true
                        }

                        style: ButtonStyle {
                            background: Rectangle {
                                implicitHeight: titlebar.height * iconBox.iconBoundingBox
                                implicitWidth: titlebar.height * iconBox.iconBoundingBox
                                border.width:  2
                                border.color:  screenChkBoxGrp.border_color
                                color: "transparent"
                                visible: true
                                radius: screenChkBoxGrp.button_radius
                            }
                        }

                        onClicked: {
                            queryPanelLoader.toggle();
                        }
                    }
                }
            }
        }

        Rectangle {
            id: bCamera
            anchors.bottom: parent.bottom

            width: parent.width
            height: camerabarheight
            color:"black"
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
                    height: renderedRow.height
                    z: contentPanel.z
                    width: screen.width
                    spacing: rowSpacing

                    Rectangle {

                        width: screen.width
                        height: renderedRow.height // + contentRow.rowSpacing
                        color: model.index % 2 == 0 ? rowEvenColor : rowOddColor
                        border.color: "black"
                        border.width: rowSpacing
                        anchors.verticalCenter: parent.verticalCenter
                        z: contentPanel.z

                        Row {
                            id: renderedRow
                            width: screen.width // - contentRow.rowSpacing * 2
                            height: Math.max(theImage.implicitHeight,
                                             theTextArea.implicitHeight)
                            spacing: contentRow.rowSpacing
                            Image {
                                id: theImage
                                width: screen.width / 8 // - contentRow.rowSpacing * 2
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
                                spacing: 2
                                x: screen.width / 8 // + contentRow.rowSpacing
                                width: parent.width * 3 / 4 // - contentRow.rowSpacing * 2

                                Text {
                                    text: model.listingName
                                    width: parent.width
                                    renderType: Text.NativeRendering
                                    wrapMode: Text.WordWrap
                                    verticalAlignment: Text.AlignBottom
                                    horizontalAlignment: Text.AlignLeft
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
                                    verticalAlignment: Text.AlignTop
                                    horizontalAlignment: Text.AlignLeft
                                    renderType: Text.NativeRendering
                                    wrapMode: Text.Wrap
                                    font.pointSize: 9
                                }
                                Text {
                                    font.bold: true
                                    verticalAlignment: Text.AlignTop
                                    horizontalAlignment: Text.AlignLeft
                                    font.pointSize: 12
                                    wrapMode: Text.NoWrap
                                    renderType: Text.NativeRendering
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
                                verticalAlignment: Text.AlignVCenter
                                anchors.verticalCenter: parent.verticalCenter
                                //height: 36

                                text: theModel.fts
                                font.pointSize: 28
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
                                        renderType: Text.NativeRendering
                                        anchors.left: parent.left
                                        anchors.leftMargin: parent.border.width + 10
                                        anchors.verticalCenter: parent.verticalCenter
                                        verticalAlignment: Text.AlignVCenter
                                        horizontalAlignment: Text.AlignLeft
                                        wrapMode: Text.NoWrap
                                        //height: 28
                                        color: "white"
                                        font.pointSize: 16
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
                    Qt.inputMethod.hide();
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
        Component.onCompleted: {
            console.debug("screenheight x screenwidth: " + screenheight +  " x " + screenwidth);
        }
    }


}
