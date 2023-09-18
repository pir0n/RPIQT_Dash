import QtQuick

Item {
    width: 600
    height: 600

    QtObject {
        id: feederSpeed

        property int value: 0

        SequentialAnimation on value {
            loops: Animation.Infinite
            NumberAnimation { to: 180; duration: 2000 }
            NumberAnimation { to: 0; duration: 2000 }
        }
    }

    Rectangle {
        id: rectangle
        width: 600
        height: 600
        color: "#00ffffff"

        Text {
            id: text4
            x: 266
            y: 346
            width: 85
            height: 41
            color: "#ffffff"
            text: qsTr("KM/H")
            font.pixelSize: 30
        }

        Text {
            id: text_speed_val
            x: 250
            y: 265
            width: 92
            height: 70
            color: "#ffffff"
            text: feederSpeed.value
            font.pixelSize: 60
        }

        RadialShape{
            id: speed_gauge
            x: 0
            y: 0
            width: 600
            height: 600
            opacity: 0.5
            layer.smooth: true
            layer.enabled: false
            layer.samples: 8
            antialiasing: true
            penStyle: 32
            backgroundColor: "#00000000"
            dialColor: "#ffffff"
            dialType: 0
            scale: -1
            value: feederSpeed.value
            minValue: 0
            maxValue: 200

        }
    }

}
