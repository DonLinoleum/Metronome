import QtQuick
import QtQuick.Controls
import ClickButtonHandler

Window {
    width: 600
    height: 425
    visible: true
    title: qsTr("Super Metronome")

    ClickButtonHandler{id:click}

    Rectangle{
        anchors.centerIn:parent
        width: parent.width
        height: parent.height
        color: "black"
    Column{
        spacing: 30
        padding:30
        anchors.horizontalCenter: parent.horizontalCenter
        id:column

        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            Text{
                id:output
                text: "120"
                font.pixelSize: 130
                font.family: "Helvetica"
                color: "#DC143C"
                anchors.bottom: parent.bottom
            }
            Text{
                text: " bpm"
                font.pixelSize: 40
                font.family: "Helvetica"
                color: "#DC143C"
                font.capitalization: Font.AllUppercase
                anchors.bottom: parent.bottom
                bottomPadding: 20
            }
        }

    Slider{
        id:slider
        from:60
        value:120
        to:220
        stepSize:1
        width: 500
        onMoved: {output.text = value}
        anchors.horizontalCenter: parent.horizontalCenter
        background: Rectangle {
                x: slider.leftPadding
                y: slider.topPadding + slider.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: slider.availableWidth
                height: implicitHeight
                radius: 50
                color: "#bdbebf"

                Rectangle {
                    width: slider.visualPosition * parent.width
                    height: parent.height
                    color: "#21be2b"
                    radius: 50
                }
            }
        handle:Rectangle{
            x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
            y: slider.topPadding + slider.availableHeight / 2 - height / 2
            implicitWidth: 26
            implicitHeight: 26
            radius: 13
            color: "#DC143C"
            border.color: "#DC143C"
        }
    }
    Button{
        width: 100
        height: 100
        id: btn
        hoverEnabled: false
        onClicked:click.changeTempo(slider.value)
        icon.source: "images/play.png"
        icon.color: "transparent"
        icon.width: 50
        icon.height: 50
        display: Button.IconOnly

        anchors.horizontalCenter: parent.horizontalCenter
        background:Rectangle{
            anchors.fill: parent
            color: btn.down ? "#A9A9A9" : "white"
            radius: 80

            Text{
                id:buttonText
                font.pixelSize: 20
                font.family: "Helvetica"
                font.capitalization: Font.AllUppercase
                anchors.centerIn: parent
            }
        }
    }
    }
    }
}

