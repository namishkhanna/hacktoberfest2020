
 $MyEmail = "sendersemail@abc.com"
 $To = "receiversemail@abc.com"
 $Subject = "This is the automated email"
 $Body = "testing"
 $Creds = (Get-Credential -Credential "$MyEmail")
 $SMTP= "smtp.gmail.com"
 Start-Sleep 1

 Send-MailMessage -To $to -From $MyEmail -Subject $Subject -Body $Body -SmtpServer $SMTP -Credential $Creds -UseSsl -Port 587
