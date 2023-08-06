param (
    [string]$FolderPath
)

# Check if the folder path is provided as a command-line argument
if (-not $FolderPath) {
    Write-Host "Please, use -FolderPath param use the name of datastructure folder!"
    exit 1
}

# Check if the provided folder path exists
if (-not (Test-Path $FolderPath -PathType Container)) {
    Write-Host "Folder not found: $FolderPath"
    exit 1
}

# Starting Measuring the time of execution of specified data struture
Write-Host "Executing command using the folder path: $FolderPath"
Measure-Command {start-process $FolderPath/bin/.\main.exe -Wait}