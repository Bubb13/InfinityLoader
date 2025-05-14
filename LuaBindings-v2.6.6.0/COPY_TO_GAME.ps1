
param (
	[Parameter(Mandatory)][string]$OutDir,
	[Parameter(Mandatory)][string]$GamePath
)

try {
	if ($Env:DEPLOY -eq "1") {
		"LuaBindings-v2.6.6.0.dll" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\EEex\loader\$_"}
		"LuaBindings-v2.6.6.0.pdb" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\pdb\$_"}
	}
	if (($GamePath -ne ".") -and (Test-Path $GamePath)) {
		"LuaBindings-v2.6.6.0.dll", "LuaBindings-v2.6.6.0.pdb" | ForEach-Object {Copy-Item "$OutDir/$_" $GamePath}
	}
}
catch {
	Write-Output $_
	Exit -1
}
