$s = "hello world"
if("$s" -ne "") {
    Write-Host "The variable is not empty"
}

write-host $s

$Servers = Get-Content 'C:\Users\WnAdmin\Desktop\dochandling\BOSIP.txt'
Write-Host "Start"

Foreach( $Server in $Servers ) {
    $Directoriesexist = Get-ChildItem -Path \\$Server\c$\Backup\FiscalDocs_archived\POS01 | where {$_.PSIscontainer -eq 'true'}
    Write-Host $Directoriesexist
    $Directoriesexist | out-file C:\Users\WnAdmin\Desktop\ScriptLog.txt -append
}

Write-Host "End of Process"