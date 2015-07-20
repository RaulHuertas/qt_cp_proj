import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias button3: button3
    property alias button2: button2
    property alias button1: button1

    RowLayout {
        anchors.centerIn: parent

        Button {
            id: button1
            text: qsTr("Press Me 1")
        }

        Button {
            id: button2
            text: qsTr("Press Me 2")
        }

        Button {
            id: button3
            text: qsTr("Press Me 3")
        }
    }

    Slider {
        id: pitch
        x: 200
        y: 56
        minimumValue: -100
        enabled: false
        maximumValue: 100
        value: _receiver.pitch
    }

    Slider {
        id: roll
        x: 200
        y: 84
        value: _receiver.roll
        enabled: false
        minimumValue: -100
        maximumValue: 100
    }

    Slider {
        id: yaw
        x: 200
        y: 112
        value: _receiver.yaw
        enabled: false
        minimumValue: -200
        maximumValue: 200
    }

    Label {
        id: label1
        x: 120
        y: 62
        text: qsTr("Pitch")
    }

    Label {
        id: label2
        x: 120
        y: 90
        text: qsTr("Roll")
    }

    Label {
        id: label3
        x: 120
        y: 118
        text: qsTr("Yaw")
    }
}
