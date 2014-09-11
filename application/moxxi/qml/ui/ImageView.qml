/**
 * Copyright (c) 2012-2014 Microsoft Mobile.
 */

import QtQuick 2.3

Item {
    id: imageView

    // These define, how big can the shown image be at maximum.
    property int maxWidth: parent.width
    property int maxHeight: parent.height

    property string imagePath: ""
    property int fillMode: Image.PreserveAspectFit

    signal closed

    // "Closes" (hides) the ImageView and signals that the ImageView
    // has been hidden.
    function close() {
        imageView.state = "";
        imageView.z = 0;
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
            return url;

        }

        // Function, that determines should the large image be either image
        // or a generic video information image.
        function __getImagePath() {
            return imageView.imagePath;
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
    }

    MouseArea {
        // A full screen mousearea to capture clicks outside the image. If
        // clicked outside, then close the ImageView.
        x: -parent.width*1/4
        y:  -parent.height*1/4
        width: parent.width*2
        height: parent.height*2

        onClicked: {
            console.log("imageView.clicked() outside image");
            imageView.close()
        }
    }

    MouseArea {
        // This one will prevent the touch events to close the image if clicked
        // on the image itself.
        anchors.fill: parent

        onClicked: {
            console.log("imageView.clicked() inside image");
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
