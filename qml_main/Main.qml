import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.4
import QtQuick.Shapes

Window {
    width: 1024
    height: 600
    visible: true
    title: qsTr("AlphaDash v0.0.0")



    Item {
        id: mainWindowItem
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0


        Rectangle{
            id: backgroundRect
            color: "#000000"
            anchors.fill: parent

            TopBarInfo {
                id: topBarInfo
                width: 1024
                height: 100

            }

            MiddleBarInfo {
                id: middleBarInfo
                x: 0
                y: 100
                width: 1024
                height: 400
                layer.smooth: false
                layer.samples: 0
                antialiasing: true

            }



            BottomBarInfo {
                id: bottomBarInfo
                y: 500
                width: 1024
                height: 100

            }





        }
    }
}
