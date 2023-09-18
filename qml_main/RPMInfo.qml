import QtQuick

Item {
    width: 600
    height: 600
    QtObject {
        id: feederRPM

        property int value: 0

        SequentialAnimation on value {
            loops: Animation.Infinite
            NumberAnimation { to: 9000; duration: 2000 }
            NumberAnimation { to: 0; duration: 2000 }
        }
    }

    Rectangle {
        id: rectangle
        width: 600
        height: 600
        color: "#00ffffff"

        RadialShape{
            id: rpm_gauge
            x: 0
            y: 0
            width: 600
            height: 600
            opacity: 0.5
            scale: -1
            value: feederRPM.value
            minValue: 0
            maxValue: 10000
        }

        Text {
            id: textRpmValue
            x: 250
            y: 265
            width: 144
            height: 75
            color: "#ffffff"
            text: feederRPM.value
            font.pixelSize: 60
        }

        Text {
            id: rpmStaticText
            x: 266
            y: 346
            width: 69
            height: 40
            color: "#ffffff"
            text: qsTr("RPM")
            font.pixelSize: 30
        }

    }

}
