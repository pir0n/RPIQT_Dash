import QtQuick
import QtQuick.Controls 6.4

Item {
    id: item1
        Rectangle {
            color: white
        }

        ProgressBar {
            id: oilPressBar
            width: 200
            height: 30
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 40
            value: 0.5
        }

        ProgressBar {
            id: waterPressBar
            x: -8
            y: -8
            width: 200
            height: 30
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: oilPressBar.right
            value: 0.5
            anchors.leftMargin: 40
        }

        ProgressBar {
            id: turboPressBar
            x: -8
            y: -8
            width: 200
            height: 30
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: waterPressBar.right
            value: 0.5
            anchors.leftMargin: 40
        }

        Text {
            id: text1
            x: 98
            y: 71
            color: "#0433ff"
            text: qsTr("Water Pressure")
            font.pixelSize: 12
        }

        Image {
            id: img_oil_press
            x: 927
            width: 67
            height: 55
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            source: "../img/low_oil_pressure.png"
            anchors.rightMargin: 30
            fillMode: Image.PreserveAspectFit
        }
}
