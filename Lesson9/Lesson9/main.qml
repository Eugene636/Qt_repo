import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import com.fileloader 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Task schedules")


TextArea {
    id: task_name
    anchors.left: parent.left
    anchors.right: write_button.left
    y:20
    height: 40
    background: Rectangle {
        anchors.fill: parent
        color: "bisque"
    }
    text: loader.getTaskName()
}
Text {
    id: task_name_sign
    anchors.left: parent.left
    anchors.right: write_button.left
    height:20
    text: "Task name:"
}

Button {
    id: write_button
    anchors.right: parent.right
    width: 40
    height: 50
    x: 600
    background: Rectangle {
        anchors.fill: parent
        color: "red"
        Text {
        id: button_text
        anchors.left: parent.left
        text: "write"
        }
    }
    onClicked: {
    if (loader.saveTask (task_name.text, deadline.text, overwrite.text)) {
        reaction.clear()
        reaction.insert(0, "Task saved")
        task_name.clear()
        deadline.clear()
        overwrite.clear()
        number_tasks.text = loader.number_tasks
    }
    else {
        reaction.clear()
        reaction.insert(0, "Task can not empty fields. Data format is dd.mm.yyyy")
    }
    }
}
Button {
    id: new_task
    anchors.right: parent.right
    anchors.top: write_button.bottom
    width: 40
    height: 50
    x: 600
    background: Rectangle {
        anchors.fill: parent
        color: "blue"
        Text {
        id: new_button_text
        anchors.left: parent.left
        text: "reset"
        }
    }
    onClicked: {
    task_name.clear()
    deadline.clear()
    overwrite.clear()
    }
}
Text {
    id: deadline_sign
    anchors.left: parent.left
    anchors.right: write_button.left
    height:20
    y: 60
    text: "Deadline:"
}

TextArea {
    id: number_tasks
    anchors.right: parent.right
    anchors.top: new_task.bottom
    width: 40
    height: 50
    x: 600
    text: loader.number_tasks
    background: Rectangle {
        anchors.fill: parent
        color: "bisque"
    }
}

TextArea {
    id: deadline
    width: task_name.width
    height: 40
    y: 80
    background: Rectangle {
        anchors.fill: parent
        color: "bisque"
    }
    text: loader.getDeadline()
}
FileLoader {
    id: loader
}
Text {
    id: overwrite_sign
    anchors.left: parent.left
    anchors.right: write_button.left
    height:20
    y: 120
    text: "Task abstract:"
}

TextArea {
    id: overwrite
    width: task_name.width
    height: 110
    y: 140
    background: Rectangle {
       anchors.fill: parent
       color: "bisque"
    }
    text: loader.getTask()
}
TextArea {
    id: reaction
    width: task_name.width
    height: 40
    y: 270
    background: Rectangle {
       anchors.fill: parent
       color: "bisque"
    }

}
onClosing: {
      close.accepted = false
      loader.writeTask(task_name.text, deadline.text, overwrite.text)
      close.accepted = true
}

}
