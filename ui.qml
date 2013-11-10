import QtQuick 1.1



Rectangle {
    width: 38
    TextInput {
        id: text_input1
        x: 198
        y: 310
        width: 80
        height: 20
        text: qsTr("DEu certo")
        z: 1
        font.pixelSize: 12
    }

    Rectangle {
        id: rectangle1
        x: -75
        y: -62
        width: 585
        height: 485
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#47c6b1"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }

        Text {
            id: text1
            x: 54
            y: 142
            objectName: "tvnome"
            text: qsTr("Nome")
            font.pixelSize: 12
        }

        Text {
            id: text2
            x: 54
            y: 217
            text: qsTr("Email")
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 54
            y: 287
            text: qsTr("Telefone")
            style: Text.Sunken
            font.pixelSize: 12
        }
    }


}
