
param (
	[Parameter(Mandatory)][string]$OutDir,
	[Parameter(Mandatory)][string]$GamePath
)

try {
	if ($Env:DEPLOY -eq "1") {
		"InfinityLoaderCommon.dll" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\EEex\loader\$_"}
		"InfinityLoaderCommon.pdb" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\pdb\$_"}
	}
	if (($GamePath -ne ".") -and (Test-Path $GamePath)) {
		"InfinityLoaderCommon.dll", "InfinityLoaderCommon.pdb" | ForEach-Object {Copy-Item "$OutDir/$_" $GamePath}
	}
}
catch {
	Write-Output $_
	Exit -1
}
