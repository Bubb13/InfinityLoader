
param (
	[Parameter(Mandatory)][string]$OutDir,
	[Parameter(Mandatory)][string]$GamePath
)

try {
	if ($Env:DEPLOY -eq "1") {
		"EEex.dll" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\EEex\loader\v2.6.6.0\dll\$_"}
		"EEex.pdb" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\pdb\v2.6.6.0\$_"}
	}
	if (($Env:GAME_VERSION -eq "v2.6.6.0") -and ($GamePath -ne ".") -and (Test-Path $GamePath)) {
		"EEex.dll", "EEex.pdb" | ForEach-Object {Copy-Item "$OutDir/$_" $GamePath}
	}
}
catch {
	Write-Output $_
	Exit -1
}
