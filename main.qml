import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
import QtQuick.Window

/* import Db */

ApplicationWindow {
    width: 600
    height: 600
    visible: true
    title: "Oogway Login"

    Material.theme: Material.Dark

    /* onActiveFocusItemChanged: print("activeFocusItem: " + activeFocusItem) */

    Window {
	id: dashboard
	x: 0
	y: 0
	width: 500
	height: 500
	visible: false
	title: "Oogway Dashboard"
	
	Label {
	    id: "dashboard_title"
	    text: "Oogway Dashboard"
	}
    }

    ColumnLayout {
	id: layout
	anchors.horizontalCenter: parent.horizontalCenter
	anchors.verticalCenter: parent.verticalCenter

	Label {
	    id: login_header
	    text: "Oogway Log-In"
	    Layout.margins: 50
	    Layout.fillWidth: true
	    font.pixelSize: 30
	}
	
	RowLayout {
	    Label {
		text: "Username:"
		width: 200
		font.pixelSize: 15
	    }
	    TextInput {
		id: username
		objectName: "username"
		text: "..."
		font.pixelSize: 12
		font.weight: Font.Normal
		maximumLength: 20
		color: "white"
		Layout.margins: 10
		Layout.fillWidth: true
		onAccepted: console.log("Values: " + username.text + " " + password.text + " " + two_fa_code.text)
		
		width: 400
		height: 50
	    }
	}
	RowLayout {
	    Label {
		text: "Password:"
		width: 200
		font.pixelSize: 15
	    }
	    TextInput {
		id: password
		objectName: "password"
		text: "..."
		font.pixelSize: 12
		font.weight: Font.Normal
		maximumLength: 20
		echoMode: TextInput.Password
		color: "white"
		visible: true
		Layout.margins: 10
		Layout.fillWidth: true
		onAccepted: console.log("Values: " + username.text + " " + password.text + " " + two_fa_code.text)
		
		width: 400
		height: 50
	    }
	}
	RowLayout {
	    Label {
		text: "2FA Code:"
		width: 200
		font.pixelSize: 15
	    }
	    TextInput {
		id: two_fa_code
		objectName: "two_fa_code"
		width: 400
		color: "white"
		visible: true
		maximumLength: 6
		font.pixelSize: 12
		font.weight: Font.Normal
		inputMethodHints: Qt.ImhDigitsOnly
		/* echoMode: TextInput.Password */
		Layout.margins: 10
		Layout.fillWidth: true
		onAccepted: console.log("Values: " + username.text + " " + password.text + " " + two_fa_code.text)
	    }
	}
	RowLayout {
	    id: control_buttons
	    /* spacing: 200 */
	    Layout.margins: 10


	    Button {
		id: submit
		text: "Submit"
		visible: true
		Layout.fillWidth: true
		/* onClicked: console.log("Values: " + username.text + " " + password.text + " " + two_fa_code.text) */
		/* onClicked: dashboard.show() */
		/* onClicked: database.CheckLogin(username.text, password.text, two_fa_code.text) */
		
		/* background: Rectangle { */
		/*     implicitWidth: 100 */
		/*     implicitHeight: 40 */
		/*     /\* color: submit.down ? "#ff0000" : "#00ffff" *\/ */
		/*     /\* border.color: "#" *\/ */
		/*     border.width: 1 */
		/*     radius: 4 */
		/* } */
	    }
	    Button {
		id: cancel
		text: "Cancel"
		visible: true
		Layout.fillWidth: true
		onClicked: Qt.quit()
		
		/* background: Rectangle { */
		/*     implicitWidth: 100 */
		/*     implicitHeight: 40 */
		/*     color: cancel.down ? "#00ff00" : "#ff00ff" */
		/*     border.color: "#ffff00" */
		/*     border.width: 1 */
		/*     radius: 4 */
		/* } */
	    }
	}
    }
}
