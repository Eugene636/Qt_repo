import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
        Label {
            width: parent.width
            height: 30
            id: nameLabel
            text: "Your Name:"
        }
        TextArea {
            id: name
            anchors.top: nameLabel.bottom
            width: parent.width
            height: 30
            placeholderText: "Name"

        background: Rectangle {
            anchors.fill: parent
            border.color: "red"
        }
        }
        RowLayout {
            id: sexButtonsLayout
            anchors.left: parent.left
            anchors.top: name.bottom
        RadioButton {
            id: manButton
            text: "Man"
        }
        RadioButton {
            id: womanButton
            text: "Woman"
        }
        }
        Label {
            anchors.left: parent.left
            anchors.top: sexButtonsLayout.bottom
            width: parent.width
            height: 30
            id: ageLabel
            text: "Partner age:"
        }
        ComboBox {
            anchors.left: parent.left
            anchors.top: sexButtonsLayout.bottom
            id: fromAge
            model: ["18", "19", "20", "21"]
        }
        ComboBox {
            anchors.left: fromAge.right
            anchors.top: sexButtonsLayout.bottom
            id: toAge
            model: ["18", "19", "20", "21"]
        }
        TextArea {
            width: parent.width
            anchors.top: fromAge.bottom
            placeholderText: "education"
            id: educationField
            background: Rectangle {
                anchors.fill: parent
                border.color: "red"
            }
        }
        Label {
            anchors.top: educationField.bottom
            width: parent.width
            height: 30
            id: partnerInfo
            text: "Search for:"
        }
        Button {
            anchors.bottom: parent.bottom
            width: parent.width / 2
            height: 30
            text: "Registration"
            onClicked: {
                console.log(name.text)
                if (manButton.checked) console.log("Male")
                if (womanButton.checked) console.log("Female")
                console.log(fromAge.currentText)
                console.log(toAge.currentText)
                console.log(educationField.text)
            }
        }

    }
