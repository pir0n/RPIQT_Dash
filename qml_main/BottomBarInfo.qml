import QtQuick

Item {
    id: item1
    width: 1024
    height: 100



    Rectangle {
        id: rectangle
        width: 180
        height: 100
        color: "#00ffffff"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Image {
            id: rightArrowBlink
            x: 139
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            horizontalAlignment: Image.AlignHCenter
            verticalAlignment: Image.AlignVCenter
            source: "../img/left-arrow3.png"
            anchors.rightMargin: 0
            fillMode: Image.PreserveAspectFit
            rotation: 180

        }

        Image {
            id: leftArrowBlink
            x: 0
            y: 18
            anchors.verticalCenter: rectangle.verticalCenter
            anchors.left: rectangle.left
            horizontalAlignment: Image.AlignHCenter
            verticalAlignment: Image.AlignVCenter
            source: "../img/left-arrow3.png"
            anchors.leftMargin: 0
            fillMode: Image.PreserveAspectFit
        }
    }

    Image {
        id: image
        x: 8
        y: 39
        width: 48
        height: 53
        source: "../img/engine.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: image1
        x: 74
        y: 39
        width: 54
        height: 53
        source: "../img/car-battery.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: image2
        x: 887
        y: 34
        width: 54
        height: 63
        source: "../img/coolant_cold.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: image3
        x: 947
        y: 34
        width: 54
        height: 63
        source: "../img/coolant_overheat.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: image4
        x: 152
        y: 44
        width: 44
        height: 43
        source: "../img/low_fuel.png"
        fillMode: Image.PreserveAspectFit
    }
}
