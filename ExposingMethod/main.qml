import QtQuick 2.15
import QtQuick.Window 2.15
import com.fsoft.msg 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MessageBoard {
        id: msgBoard
        onMessageSent: console.log("Message from C++:", msg)
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            var result = msgBoard.postMessage("Hello from QML")
            console.log("Result of postMessage():", result)
            msgBoard.refresh();
        }
    }
}
