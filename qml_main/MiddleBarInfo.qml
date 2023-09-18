import QtQuick
import QtQuick.Controls 6.4
import QtQuick.Shapes


Item {
    id: item1


    SpeedInfo {
        id: speedInfo
        x: 484
        width: 600
        height: 600
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 30
        scale: 0.5

    }


    RPMInfo {
        id: rpmInfo
        width: 600
        height: 600
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 30
        scale: 0.5
    }

    Image {
        id: imgLowBeam
        x: -17
        y: -17
        width: 100
        height: 100
        source: "../img/beam.png"
        scale: 0.5
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: imgHighBeam
        x: 44
        y: -17
        width: 100
        height: 100
        source: "../img/high_beam.png"
        fillMode: Image.PreserveAspectFit
        scale: 0.5
        MouseArea {
              anchors.fill: parent
              onClicked: middlebarHandler.setparkingBrake(!middlebarHandler.parkingBrake)
          }
    }

    Image {
        id: imgParkingBrake
        x: 462
        y: 275
        width: 100
        height: 100
        visible: middlebarHandler.parkingBrake
        source: "../img/brake.png"
        fillMode: Image.PreserveAspectFit
        scale: 0.5



    }

    Text {
        id: serial_connection_info
        x: 11
        y: 287
        width: 166
        height: 88
        color: "#ffffff"
        text: middlebarHandler.serialInfo
        font.pixelSize: 12
        font.italic: false
        font.bold: true
    }







}
