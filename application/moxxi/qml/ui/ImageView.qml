/**
 * Copyright (c) 2012-2014 Microsoft Mobile.
 */

import QtQuick 1.1

Item {
    id: imageView

    // These are needed for VideoStreamer integration.
    //property bool showToolBar: false
    //property bool showStatusBar: false

    // These define, how big can the shown image be at maximum.
    property int maxWidth: 560
    property int maxHeight: 340

    property string imagePath: ""
    property int fillMode: Image.PreserveAspectFit

    signal closed

    // "Closes" (hides) the ImageView and signals that the ImageView
    // has been hidden.
    function close() {
        imageView.state = "";
        imageView.closed();
    }

    // The width and height will be defined by the size
    // of the shown image!
    width: img.width
    height: img.height
    opacity: 0

    Image {
        id: img

        function __urlToLocalFile(url) {
            var urlString = new String(url);
            var prefix = "file://";
            if (urlString.indexOf(prefix) === 0) {
                return urlString.substring(prefix.length);
            } else {
                return urlString;
            }
        }

        // Function, that determines should the large image be either image
        // or a generic video information image.
        function __getImagePath() {
            var prefix = "";
            if (imageView.imagePath) {
                    prefix = "image://imageprovider/imageFull/";
            }

            return prefix + imageView.imagePath;
        }

        // Image size will be automatic, determined by the imageprovider!
        //width: imageView.width
        //height: imageView.height
        sourceSize.width: imageView.maxWidth
        sourceSize.height: imageView.maxHeight
        source: __getImagePath()

        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
        smooth: true

        Column {
            visible: false
            spacing: 3

            anchors {
                top: parent.verticalCenter
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                leftMargin: 20
                rightMargin: 20
                topMargin: img.height / 4
            }

            Text {
                color: "white"
                width: parent.width
                text: img.__urlToLocalFile(model.url)
                wrapMode: Text.WrapAnywhere
                maximumLineCount: 1
                font.pixelSize: 22
            }

            Text {
                color: "white"
                width: parent.width
                visible: model.width !== 0 && model.height !== 0
                text: "Shown in size: " + model.width + " x " + model.height
                wrapMode: Text.WrapAnywhere
                maximumLineCount: 1
                font.pixelSize: 22
            }

            Text {
                color: "white"
                width: parent.width
                visible: model.fileSize !== 0
                text: "File size: " + ((model.fileSize) / 1048576).toFixed(2) + " MB";
                wrapMode: Text.WrapAnywhere
                maximumLineCount: 1
                font.pixelSize: 22
            }
        }
    }

    MouseArea {
        // A full screen mousearea to capture clicks outside the image. If
        // clicked outside, then close the ImageView.
        x: -200
        y: -200
        width: 840
        height: 560
        onClicked: {
            imageView.close()
        }
    }

    MouseArea {
        // This one will prevent the touch events to close the image if clicked
        // on the image itself.
        anchors.fill: parent
        onClicked: {
            console.log("Capturing touch events on imageView")
        }
    }


    transform: Rotation {
        id: flipAngle

        origin.x: img.width / 2
        origin.y: img.height / 2
        axis { x: 0; y: 1; z: 0 } // Rotate around y-axis.
        angle: 0
    }

    states: [
        State {
            name: "visible"
            PropertyChanges {
                target: imageView
                opacity: 1.0
            }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "visible"

            PropertyAnimation {
                target: imageView
                properties: "opacity"
                duration: 500
            }
        },
        Transition {
            from: "visible"
            to: ""

            PropertyAnimation {
                target: imageView
                properties: "opacity"
                duration: 200
            }
        }
    ]
}
