import QtQuick 2.3

Component{
    id: rowGradient

    property string colorleft
    property string colorMid
    property string colorRight
    property real breakpoint: 0.0

    Gradient {
        GradientStop { position: 0 ; color: colorLeft }
        GradientStop { position: breakpoint ; color: colorMid }
        GradientStop { position: 1 ; color: colorRight }

    }
}
