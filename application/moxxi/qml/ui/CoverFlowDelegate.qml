/**
 * Copyright (c) 2012-2014 Microsoft Mobile.
 */

import QtQuick 2.3

Item {
    id: delegateItem

    property bool isCurrentItem: PathView.isCurrentItem
    property int topMargin: 80
    property int fullImageWidth: parent.width
    property int fullImageHeight: parent.height


    //signal clicked

    Keys.onRightPressed: {
        console.loog("Right key");
        PathView.view.incrementCurrentIndex();
    }

    Keys.onLeftPressed: {
         console.loog("Left key");
        PathView.view.decrementCurrentIndex();
    }

    Keys.onDownPressed: {
        console.loog("Down key");
         largeImageLoader.item.close();
    }

    Keys.onUpPressed: {
        console.loog("Up key");
    }

    x: 0
    z: PathView.z
    height: parent.height
    width: height / 2
    scale: PathView.iconScale

    // The coverflow delegate item consists of two images with white borders.
    // The second image is flipped and has some opacity for nice mirror effect.
    Column  {
        id: delegate

        y: delegateItem.topMargin
        spacing: 5

        // White borders around the image
        Rectangle {
            id: delegateImage

            // The rectangle is a square. Make it a bit larger than the image
            // itself, so it shows the white borders around the image.
            width: delegateItem.width + 8
            height: delegateImage.width
            color: dlgImg.status === Image.Ready ? "white" : "transparent"

            // Should go on top of the reflection image when zooming.
            z: reflection.z + 1

            Image {
                id: dlgImg

                width: delegateItem.width
                height: dlgImg.width
                anchors.centerIn: parent

                // Only set sourceSize.width or height to maintain aspect ratio.
                sourceSize.width: delegateItem.width
                sourceSize.height: dlgImg.width
                clip: true

                // Don't stretch the image, and use asynchronous loading.
                fillMode: Image.PreserveAspectCrop
                asynchronous: true

                // The image will be fetched from the imageprovider -plugin.
                source: model.imageUrl

                // Smoothing slows down the scrolling even more.
                // Use it with consideration.
                //smooth: true
            }
        }

        // Reflection
        Image {
            id: reflection

            width: dlgImg.width
            height: dlgImg.height
            anchors.horizontalCenter: delegateImage.horizontalCenter
            sourceSize.width: dlgImg.width
            sourceSize.height: dlgImg.height
            clip: true

            source: model.imageUrl

            fillMode: Image.PreserveAspectCrop
            asynchronous: true

            transform : Scale {
                yScale: -1
                origin.y: dlgImg.height / 2
            }

            // Smoothing slows down the scrolling.
            //smooth: true

            // NOTE: This does not work when there's 3D transformations
            // (like rotation around Y-axis or X-axis)
            //AlphaGradient {}
        }
    }

    Loader {
        id: largeImageLoader

        anchors.centerIn: parent
        width: delegateItem.fullImageWidth
        height: delegateItem.fullImageHeight
        z: parent.z + 1

        Component {
            id: largeImage

            // View showing the real image instead of the upscaled version of it.
            ImageView {
                anchors.centerIn: parent
                // Define the maximum size for the ImageView. The more accurate
                // size will be depending on the size of the image itself (the
                // aspect ratio of the image will be preserved).
                maxWidth: parent.width
                maxHeight: parent.height

                fillMode: Image.PreserveAspectFit

                onClosed: {
                    delegateItem.state = ""
                }
            }
        }
    }

    MouseArea {
        anchors.fill: delegateItem
        onClicked: {
            console.log("delegateItem.clicked()");

            //for(var i=0,coverFlow.children
            //delegateItem.z=0;

            console.log(parent);
            console.log(delegateItem);
            coverflowBackground.hide();
        }
    }


    // Rotation depends on the item's position on the PathView.
    // I.e. nicely rotate the image & reflection around Y-axis before disappearing.
    transform: Rotation {
        origin.x: delegateImage.width / 2
        origin.y: delegateImage.height / 2
        axis { x: 0; y: 1; z: 0 } // Rotate around y-axis.
        angle: delegateItem.PathView.angle
    }

    // States and transitions for scaling the image.
    states: [
        State {
            name: ""
            PropertyChanges {
                target: delegateImage
                // Scale up the icon
                scale: 1.8
            }
        }
    ]

}
