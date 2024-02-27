import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 800
    height: 800
    visible: true

    Button {
	id: button
	text: "A Special Button"
	visible: true

	background: Rectangle {
	    implicitWidth: 100
	    implicitHeight: 40
	    color: button.down ? "#000000" : "#ffffff"
	    border.color: "#26282a"
	    border.width: 1
	    radius: 4
	}
    }

    TextInput {
	id: username
	text: Username
	visible: true

	width: 400
	height: 50
	color: "#000000"
    }
}
