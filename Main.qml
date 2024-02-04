import QtQuick
import QtQuick.Controls
import click

Window {
    width: 500
    height: 500
    visible: true
    title: qsTr("Super Metronome")

    function onValueChanged(){

    }
    Click{id:click}

    Rectangle{
        anchors.centerIn:parent
        width: parent.width
        height: parent.height
        color: "#B0E0E6"
    Column{
        spacing: 30
        padding:30
        anchors.horizontalCenter: parent.horizontalCenter
        id:column

    Image{
        source: "images/metronome.png"
        width:300
        height:200
       anchors.horizontalCenter: parent.horizontalCenter

    }
    Slider{
        id:slider
        from:60
        value:120
        to:220
        stepSize:1
        width: 500
        onMoved: {output.text = "Tempo: " + value}
        anchors.horizontalCenter: parent.horizontalCenter

    }
    Text{
        id:output
        text: "Tempo: 120"
        font.pixelSize:15
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button{
        width: 120
        height: 50
        id: btn
        hoverEnabled: false
        onClicked:click.changeTempo(slider.value)

        anchors.horizontalCenter: parent.horizontalCenter
        background:Rectangle{
            anchors.fill: parent
            color: "#c7ecee"
            border.color: "#01a3a4"
            radius: 10

            Text{
                text: "Start"
                font.pixelSize: 18
                anchors.centerIn: parent
            }
        }
    }
    }
    }
    Component.onCompleted: {
        click.valueChanged.connect(onValueChanged)
    }
}

