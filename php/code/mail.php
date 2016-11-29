<?php
// the message
$msg = "First line of text\nSecond line of text";


// use wordwrap() if lines are longer than 70 characters
$msg = wordwrap($msg,70);
$headers =  'MIME-Version: 1.0' . "\r\n"; 
$headers .= 'From: Your name <info@address.com>' . "\r\n";
$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n"; 
$mail->SMTPSecure = 'tls';
// send email
mail("namit.garg@kelltontech.com","My subject",$msg,$headers);
?> 