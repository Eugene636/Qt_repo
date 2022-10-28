import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
        Rectangle {
            id: authorizationForm
            width: parent.width
            height: parent.height - 50
            color: "darkgrey"
        Rectangle {
            id: centralRect
            width: parent.width/2
            height: 10
            anchors.centerIn: parent
            visible: false
        }
        TextArea {
            id: login
            width: parent.width/2
            height: 50
            placeholderText: "login"
            anchors.bottom: centralRect.top
            anchors.left: centralRect.left
            background: Rectangle {
                radius: 0.05*width
                anchors.fill: parent
            }
        }
        TextArea {
            id: password
            width: parent.width/2
            height: 50
            placeholderText: "password"
            anchors.top: centralRect.bottom
            anchors.left: centralRect.left
            background: Rectangle  {
                radius: 0.05*width
                anchors.fill: parent
            }
    }
        Button {
            id: setButton
            text: "Enter"
            width: parent.width/4
            height: 30
            anchors.top: password.bottom
            anchors.topMargin: 10
            anchors.left: password.left
            anchors.leftMargin: parent.width/8
        }
        SequentialAnimation {
        id: redText
        PropertyAnimation {
        target: login
        property: "color"
        to: "red"
        }
        PropertyAnimation {
        target: login
        property: "color"
        to: "black"
        }
        }
        SequentialAnimation {
        id: noise
        PropertyAnimation {
        target: authorizationForm
        property: "x"
        duration: 30
        to: "10"
        }
        PropertyAnimation {
        target: authorizationForm
        property: "x"
        duration: 30
        to: "0"
        }
        PropertyAnimation {
        target: authorizationForm
        property: "x"
        duration: 30
        to: "-10"
        }
        PropertyAnimation {
        target: authorizationForm
        property: "x"
        duration: 30
        to: "0"
        }
        }
        states: [
        State {
                name: "opacy"
                PropertyChanges {target: authorizationForm; opacity: 1; visible: true}
            },
        State {
            name: "transparent"
            PropertyChanges {target: authorizationForm; opacity: 0; visible: false}
        },
        State {
                name: "visble"
                PropertyChanges {target: authorizationForm; visible: true}
            },

        State {
            name: "invisible"
            PropertyChanges {target: authorizationForm; visible: false}
        }
        ]
        state: "opacy"
        transitions: [
        Transition {
            from: "opacy"
            to: "transparent"
            animations: [
            PropertyAnimation {
            property: "opacity"
            to: "0"
            duration: 3000
                },
            PropertyAnimation {
                property: "visible"
                to: "true"
                duration: 3000
                    },
            PropertyAnimation {
                 target: app
                 property: "visible"
                 to: "true"
                 duration: 3000
                }

            ]
            },
            Transition {
                from: "transparent"
                to: "opacy"
                animations: [
                PropertyAnimation {
                property: "opacity"
                to: "0"
                duration: 1000
                },
                PropertyAnimation {
                    property: "visible"
                    to: "false"
                    duration: 1000
                }
                ]
            }
        ]
}
        Rectangle {
            id: app
            width: parent.width
            height: parent.height - 50
            visible: false
            ListModel {
                id: booksModel
                ListElement {
                    genre: "fantastic"
                    author: "Belyaev"
                    title: "jlkj;kljkjdlfkj"
                }
                ListElement {
                    genre: "fantastic"
                    author: "Belyaev"
                    title: "opsdkfkjlkjsfd"
                }
            }
            ListView {
                anchors.fill: parent
                model: booksModel
                spacing: 1
                section.delegate: Rectangle {
                    width: parent.width
                    height: 20
                    color: "lightblue"
                    Text {
                    anchors.centerIn: parent
                    text: section
                    color: "darkblue"
                    font.weight: Font.Bold
                    }
                }
                section.property: "genre"
                delegate: Rectangle {
                    width: list.width
                    height: 50
                    border.width: 1
                    border.color: "darkgray"
                    color: "lightgray"
                    Column {
                    anchors.fill: parent
                    Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text { text: "Автор"; font.weight: Font.Bold}
                    Text { text: author}
                    spacing: 20
                    }
                    Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text { text: "Название"; font.weight: Font.Bold}
                    Text { text: title }
                    spacing: 20
                    }
                    focus: true
                    }

                }

            }
        }

        Button {
          id: visibility
          text: "visibility"
          width: parent.width/4
          height: 50
          background: Rectangle {
          anchors.fill: parent
          color: "darkgrey"
          radius: parent.width*0.02
          }
          anchors.bottom: parent.bottom
          anchors.left: parent.left
          anchors.leftMargin: (parent.width - width)/2
          onClicked: {
                    if (authorizationForm.state === "opacy") {
                    authorizationForm.state = "transparent"
                    }
                    else {
                        authorizationForm.state = "opacy"
                        app.visible = false
                    }
                   console.log(authorizationForm.state)
                }
        }
        Button {
            anchors.left: visibility.right
            anchors.bottom: parent.bottom
            height: 50
            id: vibration
            onClicked: {
            redText.running = true
            noise.running = true
            }
        }
}

