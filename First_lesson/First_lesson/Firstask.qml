import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle{
    height: 150
    width: 425
    border.color: "black"
    TextArea {
        id: perimeter
        height: 50
        width: 100
        x: parent.x+25
        y: 0
        background: Rectangle {
            height: parent.height
            width: parent.width
            border.color: "black"
        }
    }
    TextInput {
        height: 50
        width: 100
        x: parent.x+25
        y: parent.y+50
        text: "      p"
        readOnly: true
    }
    TextArea {
        id: aSide
        height: 50
        width: 100
        x: parent.x+125
        y: parent.y+0
        background: Rectangle {
            height: parent.height
            width: parent.width
            border.color: "black"
        }
    }
    TextInput {
        height: 50
        width: 100
        x: parent.x+125
        y: parent.y+50
        text: "      a"
        readOnly: true
    }

    TextArea {
        id: bSide
        height: 50
        width: 100
        x: parent.x+225
        y: parent.y+0
        background: Rectangle {
            height: parent.height
            width: parent.width
            border.color: "black"
        }
    }
    TextInput {
        height: 50
        width: 100
        x: parent.x+225
        y: parent.y+50
        text: "      b"
        readOnly: true
    }
    TextArea {
        id: cSide
        height: 50
        width: 100
        x: parent.x+325
        y: parent.y+0
        background: Rectangle {
            height: parent.height
            width: parent.width
            border.color: "black"
        }
    }
    TextInput {
        height: 50
        width: 100
        x: parent.x+325
        y: parent.y+50
        text: "      c"
        readOnly: true
    }
    TextInput {
        height: 50
        width: 100
        x: parent.x+25
        y: parent.y+100
        text: "      square="
        readOnly: true
    }
    TextArea {
        id: squareField
        height: 50
        width: 100
        x: parent.x+125
        y: parent.y+100
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
            var hPer = perimeter.text/2
            var square = hPer*(hPer - aSide.text)*(hPer - bSide.text)*(hPer - cSide.text)
            square = Math.sqrt(square)
            squareField.text = square
        }
    }


}
