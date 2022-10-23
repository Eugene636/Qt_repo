import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    PropertyAnimation {
        id: rectangleAnimation
        target: basicRectangle
        property: "rotation"
        from: 0
        to: 360
        loops: 1
        duration: 5000
    }

    Rectangle {
        id: basicRectangle
        width: 150
        height: 150
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton | Qt.LeftButton
            onClicked: {
                if (mouse.button === Qt.LeftButton)
                basicRectangle.color= Qt.rgba (Math.random(), Math.random(), Math.random(), Math.random())
                if (mouse.button === Qt.RightButton)
                    rectangleAnimation.running = true
                }
            onDoubleClicked: {
                if (mouse.button === Qt.LeftButton)
                if (basicRectangle.radius === 0) basicRectangle.radius = height/2
                else basicRectangle.radius = 0
            }
        }

    }
}
