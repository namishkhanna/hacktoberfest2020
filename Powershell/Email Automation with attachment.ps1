
 $MyEmail = "sendersemail@abc.com"
 $To = "receiversemail@abc.com"
 $Subject = "This is the automated email"
 $Body = "testing"
 $Creds = (Get-Credential -Credential "$MyEmail")
 $SMTP= "smtp.gmail.com"
 Start-Sleep 1
 $att = $file
 file = "File Path"
 


 Send-MailMessage -To $to -From $MyEmail -Subject $Subject -Body $Body -Attachments $att -SmtpServer $SMTP -Credential $Creds -UseSsl -Port 587
