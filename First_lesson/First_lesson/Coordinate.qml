import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQml 2.0
Rectangle {
    property string xText : coordinateX.text
    property string yText: coordinateY.text
    property string titleText
    height: 100
    width: 100
    TextArea {
        id: coordinateX
        height: 50
        width: 50
        background: Rectangle {
            width: parent.width
            height: parent.height
            border.color: "black"
        }
    }
    TextInput {
        height: 50
        width: 50
        anchors.top: coordinateX.bottom
        text: titleText+"x"
    }
    TextArea {
        id: coordinateY
        height: 50
        width: 50
        anchors.left: coordinateX.right
        background: Rectangle {
            width: parent.width
            height: parent.height
            border.color: "black"
        }
    }

    TextInput {
        height: 50
        width: 50
        anchors.left: coordinateX.right
        anchors.top: coordinateX.bottom
        text: titleText+"y"
    }
}
