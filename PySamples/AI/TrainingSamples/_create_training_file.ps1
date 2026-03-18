# run_batch.ps1

# This line moves the focus to the folder where this script is saved
Set-Location -Path $PSScriptRoot

$NumberOfSamples = 1

Write-Host "Generating $NumberOfSamples training samples..." -ForegroundColor Cyan

# Now it will find generate_samples.py in the same folder
python _create_training_file.py $NumberOfSamples

Write-Host "Done! Check your folder for the new .py files." -ForegroundColor Green
Read-Host "Press Enter to continue..."
