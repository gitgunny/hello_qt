import QtQuick
import QtQuick.Controls

Window {
    width: 360
    height: 570
    visible: true
    title: qsTr("Gunny Arduino Control")

    BusyIndicator {
        id: leftIndicator
        x: 40
        y: 15
        width: 100
        height: 100
        visible: true
    }

    BusyIndicator {
        id: rightIndicator
        x: 220
        y: 15
        width: 100
        height: 100
        visible: false;
    }

    Button {
        id: leftButton
        x: 5
        y: 140
        width: 170
        height: 300
        text: qsTr("좌측 깜빡이")
        onClicked: {
            Indicator.getLeftIndicatorVisible(leftIndicator.visible);
        }
    }

    Button {
        id: rightButton
        x: 185
        y: 140
        width: 170
        height: 300
        text: qsTr("우측 깜빡이")
        onClicked: {
            Indicator.getRightIndicatorVisible(rightIndicator.visible);
        }
    }

    Button {
        id: hazardButton
        x: 5
        y: 450
        width: 350
        height: 100
        text: qsTr("비상등")
    }
}
