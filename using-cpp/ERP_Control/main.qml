import QtQuick 2.12
import QtQuick.Controls 2.5
import unmansol.erp42.pcanmanager 0.1
import unmansol.erp42.canmanager 0.1

ApplicationWindow {
    id: root
    visible: true
    width: 1280
    height: 720
    title: qsTr("UNMANNED ERP42 CONTROL")

    PCanManager {
        id: pcan
    }

    CanManager{
        id: canmanager
        frameID: textInputID.text
        frameData: textInputDATA.text
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        PCanConfPage {
        }

        Page2Form {
        }
    }

//    ComboBox {
//        id: comboBox1
//        x: 660
//        y: 54
//        model: comboModel.comboList
//        onActivated: {
//            console.log("combomodel activated" + comboBox1.currentIndex)
//            comboModel.currentIndex = comboBox1.currentIndex
//         }

//    }


    Text {
        id: textID
        x: 700
        y: 70
        width: 100
        height: 40
        font.pixelSize: 12
        text: "Frame ID"

    }

    TextField {
        id: textInputID
        x: 680
        y: 90
        width: 100
        height: 40
        font.pixelSize: 12
        placeholderText: "Frame ID"
    }

    Text {
        id: textData
        x: 930
        y: 70
        width: 100
        height: 40
        font.pixelSize: 12
        text: "DATA"

    }

    TextField {
        id: textInputDATA
        x: 800
        y: 90
        width: 300
        height: 40
        font.pixelSize: 12
        placeholderText: "Data"
    }

    Button {
        id: proccessButton
        x: 1120
        y: 90
        width: 70
        height: 40
        text: "Send"
        onClicked: canmanager.buttontest()
    }


    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("PCAN Conf")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }
}
