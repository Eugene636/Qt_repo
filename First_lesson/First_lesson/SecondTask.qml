import QtQuick 2.0
import QtQuick.Controls 2.0
Rectangle {
    Coordinate {
        id: pointA
        titleText: "    A"
    anchors.left: clicked.right}
    Coordinate {
        id: pointB
        titleText: "    B"
        anchors.left: pointA.right
    }
    Coordinate {
        id: pointC
        titleText: "    C"
        anchors.left: pointB.right
    }

    TextInput {
        height: 50
        width: 100
        x: 25
        y: 100
        text: "      square="
        readOnly: true
    }
    TextArea {
        id: squareField
        height: 50
        width: 100
        x: 125
        y: 100
        background: Rectangle {
            height: parent.height
            width: parent.width
            border.color: "black"
        }
    }

    Button {
        id: clicked
        width: 25
        height: 50
        onClicked: {
            var ABx = pointB.xText - pointA.xText
            var ABy = pointB.yText - pointA.yText
            var ACx = pointC.xText - pointA.xText
            var ACy = pointC.yText - pointC.yText
            var square = Math.abs((ABx*ACy - ABy*ACx)/2)
            squareField.text = square
        }
    }
}
